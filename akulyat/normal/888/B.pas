Program CodeF_Edu_32;
var s:string;
    i,n,d,u,r,l,itog:longint;

begin
readln(n);
readln(s);
itog:=0;
for i:=1 to length(s) do
  begin
  if s[i]='U' then inc(u);
  if s[i]='D' then inc(d);
  if s[i]='L' then inc(l);
  if s[i]='R' then inc(r);  
  end;

if l<r then itog:=itog+2*l else
  itog:=itog+2*r;
if u<d then itog:=itog+2*u else
  itog:=itog+2*d;
writeln(itog);
end.