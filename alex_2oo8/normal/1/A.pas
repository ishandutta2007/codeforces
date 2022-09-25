program problem1;

var n, m, a, x, y: qWord;

begin
  readln( n, m, a );
  x := n div a;
  if ( ( n mod a ) > 0 ) then
    inc( x );
  y := m div a;
  if ( ( m mod a ) > 0 ) then
    inc( y );

  writeln( x * y );
end.