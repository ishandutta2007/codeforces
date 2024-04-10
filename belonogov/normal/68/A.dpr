uses
  Math;

var
  k, p1, p2, p3, p4, a, b: longint;


begin
  read(p1, p2, p3, p4, a, b);
  k := min(min(p1, p2), min(p3, p4));
  if (k <= b) and (a <= k) then write(k - a);
  if (k > b) then write(b - a + 1);
  if (k < a) then write(0);


end.