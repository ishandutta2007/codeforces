program problem2;
const d = 1000000007;

var n, m, k: word;
    i: longWord;
    ans: qWord;

begin
  readln( n, m, k );

  if ( k > n ) or ( k = 1 ) then
  begin
    ans := 1;
    for i := 1 to n do
      ans := ( ans * m ) mod d;
  end
  else if ( k = n ) then
  begin
    ans := 1;
    for i := 1 to ( (n+1) div 2 ) do
      ans := ( ans * m ) mod d;
  end
  else if ( k mod 2 ) = 1 then
    ans := m * m
  else
    ans := m;

  writeln( ans );
end.