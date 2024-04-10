const
  lit = 0.0001;

var
  a: array[1..1000] of longint;
  min, max: extended;
  n, i: longint; 

begin
  read(n);
  for i := 1 to n do
    read(a[i]);

  min := 0;
  max := 1000000000;
  for i := 1 to n do
  begin
    if (a[i] * 10) / i > min then
      min := (a[i] * 10) / i;

    if ((a[i] + 1) * 10) / i < max then
      max := ((a[i] + 1) * 10) / i;
  end;

  i := n;
  if trunc((max * (i + 1) - lit)) div 10 = trunc((min * (i + 1) + lit)) div 10 then
  begin
    writeln('unique');
    writeln((trunc((max * (i + 1)) - lit)) div 10)
  end
  else
    writeln('not unique');


end.