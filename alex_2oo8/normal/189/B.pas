program problem2;
uses math;

var i, j, w, h: longWord;
    sum: qWord;

begin
  readln( w, h );

  sum := 0;
  for i := 1 to ( w div 2 ) do
    for j := 1 to ( h div 2 ) do
      inc( sum, ( ( w - (2*i) + 1 ) * ( h - (2*j) + 1 ) ) );

  writeln( sum );
end.