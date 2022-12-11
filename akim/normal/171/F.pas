var a:array[2..1000000]of boolean;
    b:array[0..500000]of longint;
    i,f,k,m,l:longint;
begin
 for i:=2 to 1000000 do
 begin
  if a[i]=false then
  begin
   inc(b[0]);
   b[b[0]]:=i;
   f:=i*2;
   while f<1000000 do
   begin
    a[f]:=true;
    f:=f+i;
   end;
  end;
 end;
 readln(l);
 for i:=1 to b[0] do
 begin
  m:=b[i];k:=0;
  while m<>0 do
  begin
   k:=k*10+m mod 10;
   m:=m div 10;
  end; 
  f:=1;
  if k<>b[i] then
  begin
   if a[k]=false then dec(l);
   if l=0 then begin writeln(b[i]);halt(0);end;
  end;
 end; 
 close(output);
end.