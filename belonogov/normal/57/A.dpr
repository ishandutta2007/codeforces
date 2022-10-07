uses Math;

var
  n, x1, x2, y1, y2: longint;

begin
  read(n, x1, y1, x2, y2);
  if (abs(x1 - x2) <> n) and (abs(y1 - y2) <> n) then
    write(abs(x1 - x2) + abs(y1 - y2));

  if (abs(x1 - x2) = n) then
    if n - y1 + n - y2 > y1 + y2 then
      write(y1 + y2 + n)
    else
      write(n * 3 - y1 - y2);

  if (abs(y1 - y2) = n) and (abs(x1 - x2) <> n) then
    if n - x1 + n - x2 > x1 + x2 then
      write(x1 + x2 + n)
    else
      write(n * 3 - x1 - x2);


end.