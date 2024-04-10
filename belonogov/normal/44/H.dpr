var
  n, i, j, i1, j1: longint;
  sum: int64;
  s: string;
  a: array[1..100] of int64;
  b: array[1..100, 0..9] of int64;
  q: boolean;


begin
  readln(s);
  n := length(s);
  for i := 1 to n do
    a[i] := ord(s[i]) - ord('1') + 1;

  sum := 0;
  for i := 0 to 9 do
  begin

    b[1, i] := 1;
    for j := 2 to n do
      for i1 := 0 to 9 do
      begin
        if (i1 + a[j]) mod 2 = 0 then
          b[j, (i1 + a[j]) div 2] := b[j, (i1 + a[j]) div 2] + b[j - 1, i1];
        if (i1 + a[j]) mod 2 = 1 then
        begin
          b[j, (i1 + a[j]) div 2] := b[j, (i1 + a[j]) div 2] + b[j - 1, i1];
          b[j, (i1 + a[j]) div 2 + 1] := b[j, (i1 + a[j]) div 2 + 1] + b[j - 1, i1];
        end;
      end;

    for i1 := 0 to 9 do
    sum := sum + b[n, i1];
    for i1 := 1 to n do
      for j1 := 0 to 9 do
        b[i1, j1] :=0;      
  end;

  q := true;
  for i := 1 to n - 1 do
    if not (((a[i] - a[i + 1]) <= 1) and (a[i] - a[i + 1] >= -1)) then q := false;
  if q then dec(sum);
  writeln(sum);
end.