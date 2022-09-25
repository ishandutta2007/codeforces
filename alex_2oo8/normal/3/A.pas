program problem1;
uses math;

var x1, x2, y1, y2, dx, dy, i, k, n: longWord;
    chr: char;
    str: string;

begin
  read( chr );
  x1 := ord( chr ) - ord( 'a' );
  readln( y1 );
  read( chr );
  x2 := ord( chr ) - ord( 'a' );
  readln( y2 );

  dx := abs( x1 - x2 );
  dy := abs( y1 - y2 );
  n := max( dx, dy );
  k := min( dx, dy );

  writeln( n );

  if ( x2 > x1 ) then
    str := 'R'
  else
    str := 'L';

  if ( y2 > y1 ) then
    str := str + 'U'
  else
    str := str + 'D';

  for i := 1 to k do
    writeln( str );

  for i := 1 to ( dx - k ) do
    writeln( str[1] );

  for i := 1 to ( dy - k ) do
    writeln( str[2] );
end.