program problem4;
type tArr = array[1..20000] of integer;
     tDivArr = array[0..1000] of word;

function getDivenders( x: word ): tDivArr;
var i: word;
    incr: byte;
    a: tDivArr;
begin
  a[0] := 0;

  if ( x mod 2 ) = 1 then
    incr := 2
  else
    incr := 1;
  i := 1 + incr;
  while i <= trunc( sqrt( x ) ) do
  begin
    if ( x mod i ) = 0 then
    begin
      if ( x div i ) >= 3 then
      begin
        inc( a[0] );
        a[ a[0] ] := i;
      end;
      if i >= 3 then
      begin
        inc( a[0] );
        a[ a[0] ] := x div i;
      end;
    end;
    i := i + incr;
  end;

  getDivenders := a;
end;

var n, i, j, y: word;
    t: tArr;
    d: tDivArr;
    max, sum: longInt;

begin
  max := 0;

  readln( n );
  d := getDivenders( n );
  for i := 1 to n do
  begin
    read( t[i] );
    max := max + t[i];
  end;
  readln;

  for i := 1 to d[0] do
  begin
    for j := 0 to ( d[i] - 1 ) do
    begin
      sum := 0;
      y := 1 + j;
      while y <= n do
      begin
        sum := sum + t[y];
        y := y + d[i];
      end;
      if ( sum > max ) then
        max := sum;
    end;
  end;

  writeln( max );
end.