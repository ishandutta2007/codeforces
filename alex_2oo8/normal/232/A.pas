program problem1;

var i, j, k, i2, i3: longWord;
    cnt: array[1..100] of longWord;
    ans: array[ 1..100, 1..100 ] of byte;

begin
  fillchar( ans, sizeOf(ans), 0 );

  readln( k );

  cnt[1] := 0;
  for i := 2 to 100 do
    cnt[i] := ( i * (i-1) ) div 2;

  i := 100;
  while ( ( ( i * (i-1) * (i-2) ) div 6 ) > k ) do
    dec( i );

  for i2 := 1 to i do
    for i3 := 1 to i do
      if ( i2 <> i3 ) then
        ans[i2][i3] := 1;

  dec( k, ( ( i * (i-1) * (i-2) ) div 6 ) );
  j := i + 1;
  while ( k > 0 ) do
  begin
    while ( cnt[i] > k ) do
      dec( i );

    dec( k, cnt[i] );
    for i2 := 1 to i do
    begin
      ans[j][i2] := 1;
      ans[i2][j] := 1;
    end;

    inc( j );
  end;

  writeln( '100' );
  for i := 1 to 100 do
  begin
    for j := 1 to 100 do
      write( ans[i][j] );
    writeln();
  end;
end.