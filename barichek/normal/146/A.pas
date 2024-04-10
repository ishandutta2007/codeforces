uses math;
var
  s:string;
  n,s1,s2:longint;
  i:longint;
begin
  readln(s);
  readln(s);
  s1:=0;
  s2:=0;
  for i:=1 to length(s) do
    if (ord(s[i])<>52) and (ord(s[i])<>55) then begin writeln('NO'); halt; end;
  for i:=1 to length(s) do
    if i<=length(s) div 2 then inc(s1,ord(s[i])-48)
    else inc(s2,ord(s[i])-48);
  if s1<>s2 then writeln('NO')
  else writeln('YES');
end.