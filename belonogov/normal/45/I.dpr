var
  a: array[1..200] of longint;
  b: array[1..200] of longint;
  n, i, uka, ukb, k, min: longint;
  nol: boolean;

begin
  read(n);
  nol := false;
  uka := 0;
  ukb := 0;

  for i := 1 to n do
  begin
    read(k);
    if k > 0 then
    begin
      inc(uka);
      a[uka] := k;
    end;
    if k < 0 then
    begin
      inc(ukb);
      b[ukb] := k;
    end;
    if k = 0 then
      nol := true;
  end;

  for i := 1 to uka do
    write(a[i], ' ');


  if ukb mod 2 = 0 then
    for i := 1 to ukb do
      write(b[i], ' ');


  if ukb mod 2 = 1 then
  begin
    min := 1;
    for i := 1 to ukb do
      if b[min] <
       b[i] then
        min := i;
    for i := 1 to min - 1 do
      write(b[i], ' ');
    for i := min + 1 to ukb do
      write(b[i], ' ');
  end;

  if (uka = 0) and (ukb <= 1) then
    if nol then
      write('0')
    else
      write(b[1]);

end.