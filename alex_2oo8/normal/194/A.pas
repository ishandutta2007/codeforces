program problem1;

var n, k: longWord;

begin
  readln( n, k );

  if ( (3*n) <= k ) then
    writeln( '0' )
  else
    writeln( (3*n) - k );
end.