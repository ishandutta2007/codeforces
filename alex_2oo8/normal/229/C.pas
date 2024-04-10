program problem3;

var n, m, i, a, b: longWord;
    ans: qWord;
    arr: array[1..1000000] of longWord;

begin
  fillchar( arr, sizeOf(arr), 0 );

  readln( n, m );

  if ( n < 3 ) then
  begin
    writeln( '0' );
    halt;
  end;

  for i := 1 to m do
  begin
    readln( a, b );
    inc( arr[a] );
    inc( arr[b] );
  end;

  ans := 0;
  for i := 1 to n do
    ans := ans + ( arr[i] * ( n - arr[i] - 1 ) );

  ans := ( n * (n-1) * (n-2) div 6 ) - ( ans div 2 );

  writeln( ans );
end.