program problem5;

type tTownRec = record
                  cnt: longWord;
                  r: array[1..3000] of longWord;
                  b: array[1..3000] of boolean;
                end;
     tDeniedRec = record
                    a, b, c: longWord;
                  end;
     tDeniedArr = array[1..100000] of tDeniedRec;
     tRec = record
              prev, curr, d: longWord;
            end;
     tArr = array[ 0..50000 ] of tRec;

procedure qsort( var arr: tDeniedArr; l, r: longWord );
var i, j: longWord;
    med, t: tDeniedRec;
begin
  if ( l < r ) then
  begin
    i := l;
    j := r;
    med := arr[ (l+r) div 2 ];
    while ( i <= j ) do
    begin
      while ( arr[i].b < med.b ) or ( ( arr[i].b = med.b ) and ( arr[i].a < med.a ) ) or ( ( arr[i].b = med.b ) and ( arr[i].a = med.a ) and ( arr[i].c < med.c ) ) do
        inc( i );
      while ( arr[j].b > med.b ) or ( ( arr[j].b = med.b ) and ( arr[j].a > med.a ) ) or ( ( arr[j].b = med.b ) and ( arr[j].a = med.a ) and ( arr[j].c > med.c ) ) do
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

    qsort( arr, l, j );
    qsort( arr, i, r );
  end;
end;

procedure binSearch( const arr: tDeniedArr; a, b, n: longWord; var l, r: longWord );
var i, j, c: longWord;
begin
  i := 1;
  j := n;
  while ( i < j ) do
  begin
    c := (i+j) div 2;
    if ( arr[c].b < b ) or ( ( arr[c].b = b ) and ( arr[c].a < a ) ) then
      i := c + 1
    else
      j := c;
  end;

  if ( arr[i].a = a ) and ( arr[i].b = b ) then
  begin
    l := i;
    j := n;
    while ( i < j ) do
    begin
      c := (i+j+1) div 2;
      if ( arr[c].b > b ) or ( ( arr[c].b = b ) and ( arr[c].a > a ) ) then
        j := c - 1
      else
        i := c;
    end;
    r := i;
  end
  else
  begin
    l := 0;
    r := 0;
  end;
end;

function check( const arr: tDeniedArr; a, b, c, l, r: longWord ): boolean;
var i, j, k: longWord;
    res: boolean;
begin
  if ( l = 0 ) and ( r = 0 ) then
    exit( true );

  i := l;
  j := r;
  while ( i <> j ) do
  begin
    k := (i+j) div 2;
    if ( arr[k].c < c ) then
      i := k + 1
    else
      j := k;
  end;
  res := arr[i].c <> c;

  exit( res );
end;

procedure writeAnswer( const arr: tArr; i: longWord );
var ans: array[1..20000] of longWord;
    j: longWord;
begin
  j := 0;
  while ( i <> 0 ) do
  begin
    inc( j );
    ans[j] := arr[i].curr;
    i := arr[i].prev;
  end;

  writeln( j - 1 );
  for i := j downTo 1 do
    write( ans[i], ' ' );
end;

var n, m, k, i, j, l, r, dl, dr: longWord;
    a: array[ 1..3000 ] of tTownRec;
    d: tDeniedArr;
    arr: tArr;

begin
  readln( n, m, k );

  for i := 1 to n do
  begin
    a[i].cnt := 0;
    for j := 1 to n do
      a[i].b[j] := false;
  end;

  for i := 1 to m do
  begin
    readln( l, r );
    inc( a[l].cnt );
    inc( a[r].cnt );
    a[l].r[ a[l].cnt ] := r;
    a[r].r[ a[r].cnt ] := l;
  end;
  for i := 1 to k do
    readln( d[i].a, d[i].b, d[i].c );

  qsort( d, 1, k );

  l := 0;
  r := 1;
  arr[0].curr := 0;
  arr[1].prev := 0;
  arr[1].curr := 1;
  arr[1].d := 0;
  while ( l < r ) do
  begin
    inc( l );
    binSearch( d, arr[ arr[l].prev ].curr, arr[l].curr, k, dl, dr );
    j := arr[l].curr;
    for i := 1 to a[j].cnt do
    begin
      if ( not a[ a[j].r[i] ].b[j] ) and ( check( d, arr[ arr[l].prev ].curr, j, a[j].r[i], dl, dr ) ) then
      begin
        inc( r );
        arr[r].prev := l;
        arr[r].curr := a[j].r[i];
        arr[r].d := arr[l].d + 1;

        a[ a[j].r[i] ].b[j] := true;

        if ( arr[r].curr = n ) then
        begin
          writeAnswer( arr, r );
          halt;
        end;
      end;
    end;
  end;

  writeln( '-1' );
end.