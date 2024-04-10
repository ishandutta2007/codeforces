var
 a,b:array[0..100000]of longint;
 x,sc,sc1,b1,q,l,m:int64;
 dfl,fl,n,k,o,i,j,i1,j1,fl1,fl2:longint;
begin
 randomize;
 readln(b1,q,l,n);
 for i:=1 to n do begin read(a[i]);  if a[i]=0 then fl1:=2; end;
 sc:=0;
 x:=b1;
 fl:=0;
 b[0]:=1000000001;
 while abs(x)<=l do
 begin
  inc(sc);
  b[sc]:=x;
  if abs(x)=abs(b[sc-1]) then begin fl:=1; break; end;
  x:=x*q;
 end;
 if fl=1 then
 begin
  if b[sc]=b[sc-1]then
  begin
   fl1:=0;
   for i:=1 to n do if a[i]=b[sc] then fl1:=1;
   if fl1=0 then begin writeln('inf'); halt; end
   else
    begin
    for i:=sc downto 0 do if b[i]<>x then break;
    if i=1 then for j:=1 to n do if b[1]=a[j] then dfl:=1;
    if(i=1)and(dfl=1)then i:=0;
    writeln(i);
   end;
   halt;
  end else
  if b[sc]<>b[sc-1] then
  begin
   fl1:=0;
   fl2:=0;
   x:=abs(b[sc]);
   for i:=1 to n do if a[i]=-x then fl1:=1 else if a[i]=x then fl2:=1;
   if(fl1=0)or(fl2=0)then begin writeln('inf'); halt; end
   else
   begin
    for i:=sc downto 0 do if abs(b[i])<>x then break;
    if i=1 then for j:=1 to n do if b[1]=a[j] then dfl:=1;
    if(i=1)and(dfl=1)then i:=0;
    writeln(i);
   end;
   halt;
  end;
  halt;
 end;

 sc1:=sc;
 for i:=1 to sc do
 begin
  fl:=0;
  for j:=1 to n do if a[j]=b[i] then begin fl:=1; break; end;
  if fl=1 then dec(sc1);
 end;
 writeln(sc1);
end.