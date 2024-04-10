uses math;
var
  a,b:array['A'..'Z']of longint;
  s,s1,s2:ansistring;
  i,j:longint;
begin
  readln(s1);
  readln(s2);
  readln(s);
  for j:=65 to 90 do
    begin
      a[chr(j)]:=0;
      b[chr(j)]:=0;
    end;

  for i:=1 to length(s1) do
    inc(a[s1[i]]);
  for i:=1 to length(s2) do
    inc(a[s2[i]]);
  for i:=1 to length(s) do
    inc(b[s[i]]);

  for j:=65 to 90 do
    if a[chr(j)]<>b[chr(j)] then begin writeln('NO'); halt; end;
  writeln('YES');
end.