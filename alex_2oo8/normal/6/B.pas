program problem2;
uses math;

var n, m, i, j, k, l, r, t, b, ans: longWord;
    c: char;
    arr: array[ 1..100, 1..100 ] of char;


begin
  ans := 0;

  readln( n, m, c, c );

  l := m;
  r := 1;
  t := n;
  b := 1;

  for i := 1 to n do
  begin
    for j := 1 to m do
    begin
      read( arr[i][j] );
      if ( arr[i][j] = c ) then
      begin
        l := min( l, j );
        r := max( r, j );
        t := min( t, i );
        b := max( b, i );
      end;
    end;

    readln;
  end;

  if ( t > 1 ) then
  begin
    k := l;
    while ( true ) do
    begin
      while ( k <= r ) and ( arr[t-1][k] = '.' ) do
        inc( k );
      if ( k > r ) then
        break;

      inc( ans );
      c := arr[t-1][k];
      while ( k <= r ) and ( arr[t-1][k] = c ) do
        inc( k );
    end;
  end;

  if ( b < n ) then
  begin
    k := l;
    while ( true ) do
    begin
      while ( k <= r ) and ( arr[b+1][k] = '.' ) do
        inc( k );
      if ( k > r ) then
        break;

      inc( ans );
      c := arr[b+1][k];
      while ( k <= r ) and ( arr[b+1][k] = c ) do
        inc( k );
    end;
  end;

  if ( l > 1 ) then
  begin
    k := t;
    while ( true ) do
    begin
      while ( k <= b ) and ( arr[k][l-1] = '.' ) do
        inc( k );
      if ( k > b ) then
        break;

      inc( ans );
      c := arr[k][l-1];
      while ( k <= b ) and ( arr[k][l-1] = c ) do
        inc( k );
    end;
  end;

  if ( r < m ) then
  begin
    k := t;
    while ( true ) do
    begin
      while ( k <= b ) and ( arr[k][r+1] = '.' ) do
        inc( k );
      if ( k > b ) then
        break;

      inc( ans );
      c := arr[k][r+1];
      while ( k <= b ) and ( arr[k][r+1] = c ) do
        inc( k );
    end;
  end;

  writeln( ans );
end.