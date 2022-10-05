Program CodeF_421_A;
var por,c,v,v0,v1,a,l,kol:integer;


begin
read(c,v0,v1,a,l);
v:=v0;
while (c>0) and (por=0) do
  begin
    inc(kol);
    c:=c-v;
    if c<=0 then por:=1;
    c:=c+l;
    if v+a<=v1 then v:=v+a 
               else v:=v1;                  
  end;
write(kol);
end.