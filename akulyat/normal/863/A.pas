Program Kvazy;
var otv:boolean;
    i,j,jna,u:longint;
    s:string;

begin
otv:=true;
read(s);
i:=1;
while (s[i]='0') and (i<length(s)) do
  inc(i);  
if i<>length(s) then
begin  
dec(i);
j:=length(s);
while s[j]='0' do
  dec(j);
jna:=j+1;  
j:=length(s)-j;
if i>j then otv:=false else
for u:=i+1 to jna-1 do
  if s[u]<>s[jna+i-u] then otv:=false;
end;

if otv=false then writeln('NO')
  else writeln('YES');


end.