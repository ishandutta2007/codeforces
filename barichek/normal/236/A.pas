uses math;
var
  a:array['a'..'z']of longint;
  s:string;
  ans:longint;
  i:longint;
begin
  read(s);
  ans:=0;

  for i:=1 to 26 do
    a[chr(i+96)]:=0;
  for i:=1 to length(s) do
    inc(a[s[i]]);
  for i:=1 to 26 do
    inc(ans,sign(a[chr(i+96)]));
  if ans mod 2=0 then writeln('CHAT WITH HER!')
  else writeln('IGNORE HIM!');
end.