program problem1;

var n, min, max, x, cnt, i: word;

begin
  cnt := 0;

  readln( n );
  read( x );

  max := x;
  min := x;

  for i := 2 to n do
  begin
    read( x );
    if ( x < min ) then
    begin
      min := x;
      inc( cnt );
    end;
    if ( x > max ) then
    begin
      max := x;
      inc( cnt );
    end;
  end;

  readln;
  writeln( cnt );
end.