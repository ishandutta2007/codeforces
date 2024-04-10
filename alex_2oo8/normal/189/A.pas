program problem1;

var n, a, b, c, sum, max: qWord;
    ka, kb, kc: longWord;

begin
  readln( n, a, b, c );

  max := 0;

  for ka := 0 to ( n div a ) do
    for kb := 0 to ( ( n - (ka*a) ) div b ) do
    begin
      kc := ( n - (ka*a) - (kb*b) ) div c;
      sum := ka + kb + kc;

      if ( ( (ka*a) + (kb*b) + (kc*c) ) = n ) and ( sum > max ) then
        max := sum;
    end;

  writeln( max );
end.