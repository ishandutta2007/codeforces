var
  n,i, uk, rez, kol,i1: longint;
  b: array[1..10000] of longint;
  s: string;
  check: boolean;

begin
  readln(n);
  readln(s);
  s := ' ' + s;
  uk := 1;
  b[1] := 0;
  for i := 1 to length(s) do
    if (s[i] = '.') or (s[i] = '!') or (s[i] = '?') then
    begin
      inc(uk);
      b[uk] := i;
    end;
  check := true;
  i := 1;
  rez := 0;
  while (i < uk) and (check) do
  begin
    kol := 0;
    i1 := i;
    while ((n >= kol + b[i + 1] - b[i]) and (i <> i1)) or ((n >= kol + b[i + 1] - b[i] - 1) and (i = i1)) do
    begin
      if i = i1 then dec(kol);
      inc(i);
      kol := kol + b[i] - b[i - 1];
    end;
    if i1 = i then
      check := false
    else
      inc(rez);
  end;

  if check then
    writeln(rez)
  else
    writeln('Impossible');

end.