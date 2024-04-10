{$O-}
var
  k, n, z, d: longint;

begin
  read(n);
  k := 1;
  d := 5;
  while d < n do
  begin
    k := k * 2;
    d := d + k * 5;
  end;
  d := d - k * 5;
  k := k div 2;
  n := n - d;
  if k = 0 then
    k := 1
  else
    k := k * 2;
  z := (n + k - 1) div (k) ;
  if z = 1 then writeln('Sheldon');
  if z = 2 then writeln('Leonard');
  if z = 3 then writeln('Penny');
  if z = 4 then writeln('Rajesh');
  if z = 5 then writeln('Howard');


end.