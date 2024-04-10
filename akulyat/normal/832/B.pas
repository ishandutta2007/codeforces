Program CodeF_425_B;
var s,g:string;
    godnoly:boolean;
    good:array[1..26]of byte;
    st,en,ploh,mz,l,i,j,n:longint;
    


begin
readln(s);
for i:=1 to length(s) do
  good[ord(s[i])-ord('a')+1]:=1;
readln(g);
l:=length(g);
for i:=1 to l do
  if g[i]='*' then mz:=i;  
readln(n);
for i:=1 to n do
  begin
  readln(s);
  godnoly:=true;
  if (length(s)<l-1) or ((length(s)<>l) and (mz=0)) then writeln('No') else
    begin
    ploh:=length(s)-l+1;
    st:=mz;
    en:=st+ploh-1;
    if mz>0 then
      for j:=mz to mz+ploh-1 do
        if good[ord(s[j])-ord('a')+1]=1 then godnoly:=false;
    for j:=1 to length(s) do
      begin
      if (j<st)  then
        if (s[j]=g[j]) or ((g[j]='?')and (good[ord(s[j])-ord('a')+1]=1)) then else
          godnoly:=false else
      if (j>en) then    
        if (s[j]=g[j-ploh+1]) or ((g[j-ploh+1]='?')and (good[ord(s[j])-ord('a')+1]=1)) then else
          godnoly:=false;
      end;
    if godnoly=false then writeln('No') else
      writeln('Yes');
    end;
  end;
end.