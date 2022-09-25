program problem1;
uses math;

var n, i, ans, k: longWord;
    arr: array[ 0..100000, 0..1 ] of longWord;

begin
  readln( n );

  ans := 0;
  k := 0;
  arr[0][0] := 25;
  arr[0][1] := 100;
  for i := 1 to n do
  begin
    readln( arr[i][0], arr[i][1] );

    if ( arr[i][0] = arr[i-1][0] ) and ( arr[i][1] = arr[i-1][1] ) then
      inc( k )
    else
      k := 1;

    ans := max( ans, k );
  end;

  writeln( ans );
end.