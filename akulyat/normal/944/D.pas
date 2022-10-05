Program TC_D;
var s:string;
    mas:array[0..40]of array[0..40]of array[0..10000]of longint;
    koll,ed,l,orda,i,j,u:longint;
    kol:array[0..40]of longint;
    ans,best:double;
    
    
    
    
begin
readln(s);
l:=length(s);
orda:=ord('a');
for i:=1 to l do
  inc(kol[ord(s[i])-orda]);
for i:=1 to l do
  for j:=i+1 to l do
    begin
    inc(mas[ord(s[i])-orda][ord(s[j])-orda][j-i]);
    inc(mas[ord(s[j])-orda][ord(s[i])-orda][l-(j-i)]);    
    end;




for i:=0 to 25 do
  begin
  best:=0;
  for u:=1 to l-1 do
    begin
    ed:=0; koll:=0;
    for j:=0 to 25 do
      begin
      koll:=koll+mas[i][j][u];
      if (mas[i][j][u]=1) then
        inc(ed);
      end;
    if (koll<>0) then
      if (best<ed/koll) then
        best:=ed/koll;
    end;
  ans+=kol[i]*best;
  end;
ans:=ans/l;  
writeln(ans);

  




end.