program problem5;

const d = 1000000007;

function pow( a, p: longWord ): longWord;
var res: qWord;
begin
  res := 1;
  while ( p > 0 ) do
  begin
    if ( odd(p) ) then
      res := ( res * a ) mod d;

    a := ( qWord(a) * a ) mod d;
    p := p div 2;
  end;

  pow := res;
end;

var n, k, i, j: longWord;
    ans: qWord;
    a, c: array[0..2000] of longWord;

begin
  readln( n, k );
  for i := 1 to n do
    read( a[i] );

  c[0] := 1;
  for i := 1 to n do
    c[i] := ( ( qWord( c[i-1] * qWord(k+i-1) ) mod d ) * pow( i, (d-2) ) ) mod d;

  for i := 1 to n do
  begin
    ans := 0;
    for j := 0 to (i-1) do
      ans := ( ans + ( qWord(c[j]) * a[i-j] ) ) mod d;

    write( ans, ' ' );
  end;
end.