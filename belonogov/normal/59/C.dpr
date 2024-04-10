var
  a: array[1..100] of boolean;
  z, i, n, k, j: longint;
  s: string;
  check: boolean;
begin
  readln(k);
  readln(s);
  n := length(s);
  check := true;

  for i := 1 to n div 2 do
  begin
    if (s[i] = '?') and (s[n - i + 1] <> '?') then
      s[i] := s[n - i + 1];

    if (s[i] <> '?') and (s[n - i + 1] = '?') then
      s[n - i + 1] := s[i];

    if (s[i] <> '?') and (s[n - i + 1] <> '?') and (s[i] <> s[n - i + 1]) then
      check := false;
  end;

  for i := 1 to n do
    a[ord(ord(s[i]) - ord('a') + 1)] := true;

  for i := (n + 1) div 2 downto 1 do
    if s[i] = '?' then
    begin
      z := 1;
      for j := k downto 1 do
        if (z = 1) and (not a[j]) then z := j;
      s[i] := chr(z + ord('a') - 1);
      s[n - i + 1] := s[i];
      a[z] := true;
    end;

  for i := 1 to k do
    if not a[i] then check := false; 

  if check then
    writeln(s)
  else
    writeln('IMPOSSIBLE');


end.