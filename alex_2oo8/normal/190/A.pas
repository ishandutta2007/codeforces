program problem1;
uses math;

var n, m: longWord;

begin
  readln( n, m );

  if ( m = 0 ) then
    writeln( n, ' ', n )
  else if ( n = 0 )  then
    writeln( 'Impossible' )
  else
    writeln( (n + max( 0, (m-n) )), ' ', (n + m - min( m, 1 )) );
end.