{$O-} {$R+}
var
  a: array[1..1000] of boolean;
  n, m, i, j, x, sum, k: longint;
  s: string;

begin
  readln(n, m);

  for i := 1 to m do
  begin
    readln(s);

    if s[8] = 'r' then
    begin
      x := 0;
      for j := 17 to length(s) do
        x := x * 10 + ord(s[j]) - ord('1') + 1;

      for j := 1 to x do
        a[j] := true;

    end;
    if s[8] = 'l' then
    begin
      x := 0;
      k := length(s);
      for j := 16 to length(s) do
        x := x * 10 + ord(s[j]) - ord('1') + 1;

      for j := x to n do
        a[j] := true;
     end;
  end;


  sum := 0;
  for i := 1 to n do
    if not a[i] then inc(sum);

  if sum <> 0 then
    writeln(sum)
  else
     writeln(-1);



end.