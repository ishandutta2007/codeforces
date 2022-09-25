program problem6;

function prime( a: longWord ): boolean;
var i: longWord;
    b: boolean;
begin
  b := true;

  for i := 2 to trunc( sqrt( a ) ) do
    if ( a mod i ) = 0 then
    begin
      b := false;
      break;
    end;

  prime := b;
end;

var n, a, b, c, k: longWord;

begin
  readln( n );

  k := 0;
  a := 12;

  while ( k < n ) do
  begin
    inc( a );
    if prime( a ) then
    begin
      b := 0;
      c := 10;
      while ( a >= ( c div 10 ) ) do
      begin
        b := b * 10 + ( ( a div ( c div 10 ) ) mod c ) mod 10;
        c := c * 10;
      end;
      if ( a <> b ) and prime( b ) then
        inc( k );
    end;
  end;

  writeln( a );
end.