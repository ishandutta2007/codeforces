program problem1;

function pow( a: qWord; p, d: longWord ): longWord;
var res: qWord;
begin
  res := 1;
  while ( p > 0 ) do
  begin
    if ( odd( p ) ) then
      res := ( res * a ) mod d;

    a := ( a * a ) mod d;
    p := p div 2;
  end;

  pow := res;
end;

var n, m, ans: longWord;

begin
  readln( n, m );

  ans := pow( 3, n, m );
  if ( ans = 0 ) then
    ans := m;

  writeln( ans - 1 );
end.