program problem1;

var k, l, m, n, d, i, cnt: longWord;

begin
  cnt := 0;

  readln( k );
  readln( l );
  readln( m );
  readln( n );
  readln( d );

  for i := 1 to d do
  begin
    if ( ( i mod k ) = 0 ) or
       ( ( i mod l ) = 0 ) or
       ( ( i mod m ) = 0 ) or
       ( ( i mod n ) = 0 ) then
       inc( cnt );
  end;

  writeln( cnt );
end.