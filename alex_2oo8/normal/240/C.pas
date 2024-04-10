program problem3;

var n, ans, i, j, k, cnt, u: longWord;
    a: array[1..1000] of boolean;
    f: text;

begin
  fillchar( a, sizeOf(a), 0 );

  assign( f, 'input.txt' );
  reset( f );
  readln( f, n );
  close( f );

  ans := 1;
  while ( (1 shl ans) < n ) do
    inc( ans );

  assign( f, 'output.txt' );
  rewrite( f );
  writeln( f, ans );

  for i := 1 to ans do
  begin
    cnt := 0;

    j := 1;
    while ( j <= n ) do
    begin
      k := j;
      while ( k < n ) and ( a[k+1] = a[j] ) do
        inc( k );

      inc( cnt, ( (k-j+2) div 2 ) );
      for u := j to ( (k+j) div 2 ) do
        a[u] := true;
      for u := ( (k+j) div 2 + 1 ) to k do
        a[u] := false;

      j := k + 1;
    end;

    write( f, cnt );
    for j := 1 to n do
      if ( a[j] ) then
        write( f, ' ', j );
    writeln( f );
  end;

  close( f );
end.