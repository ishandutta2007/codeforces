program problem3;

var cnt, level, n, i, a: longWord;
    ans: array[ 1..100000, 0..1 ] of longWord;
    arr: array[ 0..100000 ] of longWord;

begin
  cnt := 0;
  level := 0;
  arr[0] := 0;

  readln( n );
  for i := 1 to n do
  begin
    read( a );

    while ( level > a ) do
    begin
      inc( cnt );
      ans[ cnt ][0] := arr[ arr[0] ];
      ans[ cnt ][1] := ( i - 1 );
      dec( arr[0] );
      dec( level );
    end;

    while ( level < a ) do
    begin
      inc( level );
      inc( arr[0] );
      arr[ arr[0] ] := i;
    end;

  end;

  while ( arr[0] > 0 ) do
  begin
    inc( cnt );
    ans[ cnt ][0] := arr[ arr[0] ];
    ans[ cnt ][1] := n;

    dec( arr[0] );
  end;

  writeln( cnt );
  for i := 1 to cnt do
    writeln( ans[i][0], ' ', ans[i][1] );
end.