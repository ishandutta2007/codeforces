program problem1;

function min( a, b, c: word ): word;
begin
  if ( a < b ) and ( a < c ) then
    min := a
  else if ( b < c ) then
    min := b
  else
    min := c;
end;

var n, k, l, c, d, p, nl, np: word;

begin
  read( n );
  read( k );
  read( l );
  read( c );
  read( d );
  read( p );
  read( nl );
  readln( np );

  writeln( min( ( (k*l) div nl ), (c*d), ( p div np ) ) div n );
end.