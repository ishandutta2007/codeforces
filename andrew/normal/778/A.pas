var
 dl,dl1,vv:array[0..200001]of longint;
 v:array[1..26]of longint;
 a:array[0..200001]of longint;
 dpl,dpl1,mn,mj,l1,r1,i,j,n,k,sc,o,p,l,r,c:longint;
 s,s1,s2:ansistring;
begin
 mn:=maxlongint;
 readln(s);
 readln(s1);
 n:=length(s);
 //if(s[1]='e')and(s[2]='e') then writeln(length(s),' ',length(s1));
 for i:=1 to n do read(a[i]);
 l:=0;
 r:=n;
 dl[n+1]:=-1;
 dl[0]:=-1;
 //if n=200000 then writeln(length(s1));
 for j:=1 to 18 do
 begin

  if l>=r then break;
  c:=(l+r)div 2;
  if vv[c]=1 then break;
  vv[c]:=1;
  //for i:=1 to n do dl[i]:=0;
  for i:=1 to c do dl[a[i]]:=-1;
  for i:=c+1 to n do dl[a[i]]:=0;
  s2:='';

  for i:=1 to n do if dl[i]=0 then s2:=s2+s[i];
  //if(s[1]='e')and(s[2]='e') then writeln(j);
  //l1:=1;
  //for i:=1 to n do if(s[i]=s2[l1])and(dl[i]=0)then begin dl1[l1]:=dl[i]; inc(l1); if l1>length(s2) then break; end;
  l1:=length(s1);
  if length(s2)<l1 then  begin  r:=c; continue; end;
  sc:=0;

  for i:=length(s2) downto 1 do if l1=0 then break else if s2[i]=s1[l1] then dec(l1);
  if l1>0 then begin r:=c; continue; end;
  //for i:=c+1 to n do if dl[a[i]]=-1 then break;
  if (mj<c)then mj:=c;
  if -1=dl[a[c+1]] then begin writeln(c); halt; end;
  l:=c+1;
 end;
 writeln(mj);
end.