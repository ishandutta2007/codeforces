program problem2;

var a, b, m, i, ans, j: longWord;
    r: array[ 0..100000 ] of longWord;
    last: array[ 0..100000 ] of longInt;

begin
  readln( a, b, m ,r[0] );

  for i := 0 to m do
    last[i] := -1;
  last[ r[0] ] := 0;

  i := 0;
  while true do
  begin
    inc( i );
    r[i] := ( a * r[i-1] + b ) mod m;
    if ( last[ r[i] ] > -1 ) then
    begin
      writeln( i - last[ r[i] ] );
      halt;
    end
    else
      last[ r[i] ] := i;
  end;
end.