program problem3;
uses math;

var a, b, n, i, j, k, ans: longWord;
    isPrime: array[1..1000000] of boolean;

begin
  fillchar( isPrime, sizeOf(isPrime), 1 );

  readln( a, b, n );

  isPrime[1] := false;
  for i := 2 to b do
    if ( isPrime[i] ) then
      for j := i to (b div i) do
        isPrime[i*j] := false;

  k := 0;
  for i := a to b do
    if ( isPrime[i] ) then
      inc( k );

  if ( k < n ) then
  begin
    writeln( '-1' );
    halt;
  end;

  k := 0;
  i := a;
  j := a - 1;
  ans := 0;
  while ( (i+ans-1) <= b ) do
  begin
    while ( j < b ) and ( k < n ) do
    begin
      inc( j );
      if ( isPrime[j] ) then
        inc( k );
    end;

    if ( k < n ) then
    begin
      while ( k < n ) do
      begin
        dec( i );
        if ( isPrime[i] ) then
          inc( k );
      end;

      writeln( j - i + 1 );
      halt;
    end;

    ans := max( ans, (j-i+1) );

    if ( isPrime[i] ) then
      dec( k );
    inc( i );
  end;

  writeln( ans );
end.