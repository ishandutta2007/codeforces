program problem2;

var n, m, c, i: longWord;

begin
  readln( n, m );
  c := ( m + 1 ) div 2;

  for i := 1 to n do
  begin
    if ( m mod 2 ) = 1 then
    begin
      if ( i mod m ) = 1 then
        writeln( c )
      else if ( ((i-1) mod m + 1) mod 2 ) = 0 then
        writeln( c - ( i mod m ) div 2 )
      else
        writeln( c + ( (i-1) mod m ) div 2 );
    end
    else
    begin
      if ( i mod 2 ) = 0 then
        writeln( c + ( ( (i-1) mod m ) + 1 ) div 2 )
      else
        writeln( c - ( (i-1) mod m ) div 2 );
    end;
  end;
end.