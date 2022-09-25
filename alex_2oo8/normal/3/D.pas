program problem4;
type tRec = record
              p, i: longInt;
            end;
     tArrRec = record
                 next, cnt: longWord;
                 a: array[0..200] of tRec;
               end;

const l = '(';
      r = ')';

var arr: array[0..20000] of tArrRec;
    arr_i: longWord;

procedure add( rec: tRec );
var j, k, y: longWord;
    t: tRec;
    bool: boolean;
begin
  bool := false;

  j := 1;
  while ( arr[j].a[ arr[j].cnt ].p < rec.p ) and ( arr[j].next <> 0 ) do
    j := arr[j].next;

  k := 1;
  while ( k <= arr[j].cnt ) and ( arr[j].a[k].p < rec.p ) do
    inc( k );

  if ( arr[j].cnt = 200 ) then
  begin
    bool := true;
    inc( arr_i );
    arr[arr_i].next := arr[j].next;
    arr[j].next := arr_i;
    arr[arr_i].cnt := 101;
    arr[j].cnt := 100;

    for y := 1 to 101 do
      if ( y = (k-100) ) then
        arr[arr_i].a[y] := rec
      else if ( y < (k-100) ) then
        arr[arr_i].a[y] := arr[j].a[100+y]
      else
        arr[arr_i].a[y] := arr[j].a[99+y];
  end;

  for y := k to arr[j].cnt do
  begin
    t := arr[j].a[y];
    arr[j].a[y] := rec;
    rec := t;
  end;
  if ( not bool ) then
  begin
    inc( arr[j].cnt );
    arr[j].a[ arr[j].cnt ] := rec;
  end;
end;

procedure del();
var i: longWord;
begin
  for i := 1 to arr[1].cnt do
    arr[1].a[i] := arr[1].a[i+1];
  dec( arr[1].cnt );
  if ( arr[1].cnt < 100 ) and ( arr[1].next <> 0 ) then
    if ( arr[ arr[1].next ].cnt <= 100 ) then
    begin
      for i := 1 to arr[ arr[1].next ].cnt do
      begin
        inc( arr[1].cnt );
        arr[1].a[ arr[1].cnt ] := arr[ arr[1].next ].a[i];
      end;
      arr[1].next := arr[ arr[1].next ].next;
    end
    else
    begin
      inc( arr[1].cnt );
      arr[1].a[ arr[1].cnt ] := arr[ arr[1].next ].a[1];
      dec( arr[ arr[1].next ].cnt );
      for i := 1 to arr[ arr[1].next ].cnt do
        arr[ arr[1].next ].a[i] := arr[ arr[1].next ].a[i+1];
    end;
end;

var str: ansistring;
    b, ai, bi: longInt;
    i, j: longWord;
    ans: int64;
    rec: tRec;

begin
  b := 0;
  ans := 0;
  arr_i := 1;
  arr[arr_i].cnt := 0;
  arr[arr_i].next := 0;
  readln( str );

  for i := 1 to length(str) do
  begin
    if ( str[i] = l ) then
      inc( b )
    else if ( str[i] = r ) then
      dec( b )
    else
    begin
      readln( ai, bi );
      str[i] := ')';
      inc( ans, bi );
      dec( b );
      rec.p := ai - bi;
      rec.i := i;
      add( rec );
    end;

    if ( b < 0 ) then
    begin
      if ( arr[1].cnt = 0 ) then
      begin
        writeln( '-1' );
        halt;
      end;

      inc( ans, arr[1].a[1].p );
      str[ arr[1].a[1].i ] := '(';
      inc( b, 2 );
      del();
    end;
  end;

  if ( b <> 0 ) then
  begin
    writeln( '-1' );
    halt;
  end;

  writeln( ans );
  writeln( str );
end.