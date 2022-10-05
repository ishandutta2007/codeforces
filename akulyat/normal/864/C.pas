Program Fuel;
var n,a,b,f,k,zap,kol,d:longint;
    mog:boolean;



begin
mog:=true;
read(a,b,f,k);
n:=b;
d:=a-f;
kol:=k;

if ((b<f) or (b<d)) or ((k>=2) and (b<2*d)) or ((k>=3) and (b<2*f))  then writeln(-1) else
begin
n:=n-f;
dec(k);
while k>0 do
  begin
  if (kol-k) mod 2=1 then
    if n>=2*d then
      begin
      n:=n-2*d;
      end else
      begin
      n:=b;
      inc(zap);
      n:=n-2*d;
      end           else
    if n>=2*f then
      begin
      n:=n-2*f;  
      end  else
      begin
      n:=b;
      inc(zap);
      n:=n-2*f;
      end;
   dec(k);   
  end;
  
  
if (kol-k) mod 2=1 then
    if n>=d then
      begin
      n:=n-d;
      end else
      begin
      n:=b;
      inc(zap);
      n:=n-d;
      end           else
    if n>=f then
      begin
      n:=n-f;  
      end  else
      begin
      n:=b;
      inc(zap);
      n:=n-f;
      end;
writeln(zap);
end;
end.