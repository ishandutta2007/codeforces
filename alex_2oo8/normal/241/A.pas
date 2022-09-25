program problem1;
uses math;

var n, m, k, i, j, t, ans: longInt;
    s, d, maxS: array[1..1000] of longInt;

begin
  readln( m, k );
  n := m + 1;

  for i := 1 to m do
    read( d[i] );
  readln();
  for i := 1 to m do
    read( s[i] );

  maxS[1] := s[1];
  for i := 2 to m do
    maxS[i] := max( maxS[i-1], s[i] );

  t := s[1];
  ans := 0;
  i := 1;
  while ( i < n ) do
  begin
    if ( t < d[i] ) then
    begin
      j := (d[i] - t + maxS[i] - 1) div maxS[i];
      inc( t, ( j * maxS[i] ) );
      inc( ans, ( j * k ) );
    end;

    dec( t, d[i] );
    inc( ans, d[i] );
    inc( i );
    inc( t, s[i] );
  end;

  writeln( ans );
end.