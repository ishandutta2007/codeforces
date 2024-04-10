program problem1;

var n, x, y, k: longWord;

begin
  readln( n, x, y );
  k := ( n * y + 99 ) div 100;

  if ( x > k ) then
    writeln( '0' )
  else
    writeln( k - x );
end.