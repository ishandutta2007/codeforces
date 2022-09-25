program problem1;
uses math;

var n, m, k, i, j, d, a, c1, c0, x, maxMax, maxMin: longWord;
    b: array[1..100] of boolean;
    maxCnt, minCnt: array[1..100] of longWord;
    f: text;
    s: string;

begin
  assign( f, 'input.txt' );
  reset( f );

  fillchar( b, sizeOf(b), 0 );

  readln( f, m, k );
  for i := 1 to k do
  begin
    read( f, j );
    b[j] := true;
  end;
  readln( f );

  maxMin := 0;

  readln( f, n );
  for i := 1 to n do
  begin
    x := 0;
    c1 := 0;
    c0 := 0;

    readln( f, s );
    readln( f, d );
    for j := 1 to d do
    begin
      read( f, a );
      if ( a = 0 ) then
        inc( x )
      else if ( b[a] ) then
        inc( c1 )
      else
        inc( c0 );
    end;
    readln( f );

    maxCnt[i] := min( k, ( c1 + x ) );
    minCnt[i] := d - min( (m-k), ( c0 + x ) );

    maxMin := max( minCnt[i], maxMin );
  end;
  close( f );

  assign( f, 'output.txt' );
  rewrite( f );

  for i := 1 to n do
  begin
    maxMax := 0;
    for j := 1 to n do
      if ( j <> i ) then
        maxMax := max( maxMax, maxCnt[j] );

    if ( minCnt[i] >= maxMax ) then
      writeln( f, '0' )
    else if ( maxCnt[i] >= maxMin ) then
      writeln( f, '2' )
    else
      writeln( f, '1' );
  end;

  close( f );
end.