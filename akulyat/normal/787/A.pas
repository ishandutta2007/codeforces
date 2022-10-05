Program CodF_406_A;
var q1,q2:array[0..100]of longint;
    ot,a,b,c,d,i,u:longint;
    nal:boolean;

begin
read(a);
read(b);
read(c);
read(d);
ot:=-1;
for i:=0 to 100 do
  begin
    q1[i]:=b+a*i;
  end;
for i:=0 to 100 do
  begin
    q2[i]:=d+c*i;
  end;
for i:=0 to 100 do
  for u:=0 to 100 do
    if nal=false then
      if q1[i]=q2[u] then
        begin
          nal:=true;
          ot:=q1[i];
        end;
write(ot);        
end.