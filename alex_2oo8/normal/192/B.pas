program problem2;
uses math;

var n, i, l, m, a: longWord;

begin
  l := 0;
  m := 10000;

  readln( n );

  for i := 1 to n do
  begin
    read( a );

    if ( max( a, l ) < m ) then
      m := max( a, l );

    l := a;
  end;

  if ( a < m ) then
    m := a;

  writeln( m );
end.