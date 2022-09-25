program problem4;

type tProcRec = record
                  str: string;
                  t: longWord;
                  a: array[1..5] of longWord;
                end;
     tVarRec = record
                 str: string;
                 t: longWord;
               end;
     tProcArr = array[1..1000] of tProcRec;
     tVarArr = array[1..1000] of tVarRec;

function readProc(): tProcRec;
var str: string;
    i, j: longWord;
    proc: tProcRec;
begin
  readln( str );
  i := 1;
  while ( str[i] = ' ' ) do
    inc( i );
  inc( i, 5 );
  while ( str[i] = ' ' ) do
    inc( i );

  j := i;
  while ( str[j+1] <> ' ' ) and ( str[j+1] <> '(' ) do
    inc( j );

  proc.str := copy( str, i, (j-i+1) );
  proc.t := 0;
  i := j + 1;

  while ( i <= length(str) ) and ( str[i] <> ')' ) do
  begin
    while ( str[i] = ' ' ) or ( str[i] = '(' ) or ( str[i] = ',' ) do
      inc( i );

    inc( proc.t );

    if ( str[i] = 'i' ) or ( str[i] = 'I' ) then
    begin
      proc.a[ proc.t ] := 1;
      inc( i, 4 );
    end
    else if ( str[i] = 'd' ) or ( str[i] = 'D' ) then
    begin
      proc.a[ proc.t ] := 2;
      inc( i, 7 );
    end
    else if ( str[i] = 's' ) or ( str[i] = 'S' ) then
    begin
      proc.a[ proc.t ] := 3;
      inc( i, 7 );
    end
    else
    begin
      proc.a[ proc.t ] := 0;
      inc( i, 2 );
    end;

    while ( str[i] = ' ' ) do
      inc( i );
  end;

  readProc := proc;
end;

function readVar(): tVarRec;
var str: string;
    i, j: longWord;
    v: tVarRec;
begin
  readln( str );

  i := 1;
  while ( str[i] = ' ' ) do
    inc( i );

  if ( str[i] = 'i' ) or ( str[i] = 'I' ) then
  begin
    v.t := 1;
    inc( i, 4 );
  end
  else if ( str[i] = 'd' ) or ( str[i] = 'D' ) then
  begin
    v.t := 2;
    inc( i, 7 );
  end
  else
  begin
    v.t := 3;
    inc( i, 7 );
  end;

  while ( str[i] = ' ' ) do
    inc( i );

  j := i;
  while ( j < length(str) ) and ( str[j+1] <> ' ' ) do
    inc( j );

  v.str := copy( str, i, (j-i+1) );

  readVar := v;
end;

procedure qsortProc( var arr: tProcArr; l, r: longWord );
var i, j: longWord;
    t, mid: tProcRec;
begin
  if ( r > l ) then
  begin
    mid := arr[ (l+r) div 2 ];
    i := l;
    j := r;
    while ( i <= j ) do
    begin
      while ( arr[i].str < mid.str ) or ( ( arr[i].str = mid.str ) and ( arr[i].t < mid.t ) ) do
        inc( i );
      while ( arr[j].str > mid.str ) or ( ( arr[j].str = mid.str ) and ( arr[j].t > mid.t ) ) do
        dec( j );

      if ( i <= j ) then
      begin
        t := arr[i];
        arr[i] := arr[j];
        arr[j] := t;

        inc( i );
        dec( j );
      end;
    end;

    qsortProc( arr, l, j );
    qsortProc( arr, i, r );
  end;
end;

procedure qsortVar( var arr: tVarArr; l, r: longWord );
var i, j: longWord;
    mid: string;
    t: tVarRec;
begin
  if ( r > l ) then
  begin
    mid := arr[ (l+r) div 2 ].str;
    i := l;
    j := r;
    while ( i <= j ) do
    begin
      while ( arr[i].str < mid ) do
        inc( i );
      while ( arr[j].str > mid ) do
        dec( j );

      if ( i <= j ) then
      begin
        t := arr[i];
        arr[i] := arr[j];
        arr[j] := t;

        inc( i );
        dec( j );
      end;
    end;

    qsortVar( arr, l, j );
    qsortVar( arr, i, r );
  end;
end;

function readProcReq( var varr: tVarArr; m: longWord ): tProcRec;
var str, v: string;
    i, j, l, r, c: longWord;
    p: tProcRec;
begin
  readln( str );
  i := 1;
  while ( str[i] = ' ' ) do
    inc( i );

  j := i;
  while ( str[j+1] <> ' ' ) and ( str[j+1] <> '(' ) do
    inc( j );

  p.str := copy( str, i, (j-i+1) );
  p.t := 0;

  i := j + 1;
  while ( str[i] = ' ' ) do
    inc( i );

  while ( i <= length(str) ) and ( str[i] <> ')' ) do
  begin

    while ( str[i] = ' ' ) or ( str[i] = ',' ) or ( str[i] = '(' ) do
      inc( i );

    j := i;
    while ( str[j+1] <> ' ' ) and ( str[j+1] <> ')' ) and ( str[j+1] <> ',' ) do
      inc( j );

    v := copy( str, i, (j-i+1) );

    l := 1;
    r := m;
    while ( l <> r ) do
    begin
      c := (l+r) div 2;
      if ( varr[c].str < v ) then
        l := c + 1
      else
        r := c;
    end;

    inc( p.t );
    p.a[ p.t ] := varr[l].t;

    i := j + 1;
    while ( str[i] = ' ' ) do
      inc( i );
  end;

  readProcReq := p;
end;

function compare( p1, p2: tProcRec ): boolean;
var i: longWord;
    bool: boolean;
begin
  bool := true;

  for i := 1 to p1.t do
    if ( p2.a[i] <> 0 ) and ( p1.a[i] <> p2.a[i] ) then
      bool := false;

  exit( bool );
end;

var n, m, k, i, l, r, c, ans: longWord;
    proc_arr: tProcArr;
    var_arr: tVarArr;
    str: string;
    proc: tProcRec;

begin
  readln( n );
  for i := 1 to n do
    proc_arr[i] := readProc();

  qsortProc( proc_arr, 1, n );

  readln( m );
  for i := 1 to m do
    var_arr[i] := readVar();

  qsortVar( var_arr, 1, m );

  readln( k );
  for i := 1 to k do
  begin
    ans := 0;

    proc := readProcReq( var_arr, m );

    l := 1;
    r := n;
    while ( l <> r ) do
    begin
      c := (l+r) div 2;
      if ( proc_arr[c].str < proc.str ) or ( ( proc_arr[c].str = proc.str ) and ( proc_arr[c].t < proc.t ) ) then
        l := c + 1
      else
        r := c;
    end;

    while ( l <= n ) and ( proc_arr[l].str = proc.str ) and ( proc_arr[l].t = proc.t ) do
    begin
      if ( compare( proc, proc_arr[l] ) ) then
        inc( ans );

      inc( l );
    end;

    writeln( ans );
  end;
end.