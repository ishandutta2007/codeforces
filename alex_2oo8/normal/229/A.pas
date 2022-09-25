program problem1;
uses math;

function findLast( const str: ansistring; chr: char ): longWord;
var i: longWord;
begin
  i := length( str );
  while ( i > 0 ) and ( str[i] <> chr ) do
    dec( i );

  findLast := i;
end;

var n, m, i, j, k, l, ans, curr: longWord;
    a: array[1..100] of ansistring;
    p: array[ 1..100, 1..10000 ] of longWord;

begin
  readln( n, m );
  for i := 1 to n do
    readln( a[i] );

  for i := 1 to n do
  begin
    k := findLast( a[i], '1' );
    l := pos( '1', a[i] );

    if ( k = 0 ) then
    begin
      writeln( '-1' );
      halt;
    end;

    k := m - k + 1;
    l := l - 1;
    for j := 1 to m do
    begin
      p[i][j] := min( k, l );

      if ( l = 0 ) then
      begin
        k := 1;
        l := pos( '1', copy( a[i], (j+1), (m-j) ) );
        if ( l = 0 ) then
          l := pos( '1', a[i] ) + m - j - 1
        else
          l := l - 1;
      end
      else
      begin
        inc( k );
        dec( l );
      end;
    end;
  end;

  ans := n * m;
  for i := 1 to m do
  begin
    curr := 0;
    for j := 1 to n do
      inc( curr, p[j][i] );

    ans := min( ans, curr );
  end;

  writeln( ans );
end.