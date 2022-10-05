Program Easy_Vid;
var baz,numb,kol,st,nal,stoi,nap:array[1..200000]of longint;
    sob,kot,n,i,ind,vstav:longint;


begin
read(n);
for i:=1 to n do
  begin
  read(st[i]);
  inc(kol[st[i]]);
  end;

for i:=1 to n do
  begin
  if kol[i]=0 then
    begin
    inc(kot);
    numb[kot]:=i;
    end;
  end;
ind:=1;
for i:=1 to n do baz[i]:=kol[i];


for i:=1 to n do
  if kol[st[i]]>1 then
    if (((st[i]>numb[ind]) and (numb[ind]<>0)) or ((nap[st[i]]+nal[st[i]]+1=baz[st[i]]) and (kol[st[i]]<>1)) or (nap[st[i]]+stoi[st[i]]=1)) and (numb[ind]<>0) and (kol[st[i]]>1) then
      begin
      inc(nal[st[i]]);
      dec(kol[st[i]]);
      st[i]:=numb[ind];
      //writeln(i);
      inc(kol[numb[ind]]);
      inc(ind);
      inc(vstav);
      inc(stoi[st[i]]);
      end else
      inc(nap[st[i]]);
writeln(kot);
for i:=1 to n do write(st[i], ' ' );  
  
end.