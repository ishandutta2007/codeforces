uses math;
var
  a:array['a'..'z']of longint;
  s:string;
  n:longint;
  i:char;
  j:longint;
begin
  readln(n);
  readln(s);
  for i:='a' to 'z' do
    a[i]:=0;
  for j:=1 to n do
    if (ord(s[j])>=65) and (ord(s[j])<=90) then s[j]:=chr(ord(s[j])+32);
  for j:=1 to n do
    a[s[j]]:=1;

  for i:='a' to 'z' do
    if a[i]=0 then begin writeln('NO'); halt; end;
  writeln('YES');
end.