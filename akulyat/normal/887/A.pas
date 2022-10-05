Program assafasfas;
var s:string;
    k:boolean;
    kol,i,l:longint; 


begin
read(s);
l:=length(s);

for i:=1 to l do
  if s[i]='1' then
  k:=true else
  if (s[i]='0') and (k=true) then
    inc(kol);


if kol>=6 then writeln('yes') else
  writeln('no');    








end.