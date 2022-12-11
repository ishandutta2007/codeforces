var s:string;
    c0,cv,c1,l,i,v0,v1,vv:longint;
begin
 readln(s);l:=length(s);c0:=0;c1:=0;cv:=0;
 for i:=1 to l do
 case s[i] of
  '0':inc(c0);
  '1':inc(c1);
  '?':inc(cv);
 end;
 if c0+cv>c1 then writeln('00');
 if s[l]='1' then 
 begin
  v0:=c0;v1:=c1-1;vv:=cv;
  while vv<>0 do
  begin
   if v0>v1 then inc(v1) else inc(v0);
   dec(vv);
  end;
  if (v0=v1)or(v0=v1+1) then writeln('01');
 end;
 if s[l]='?' then
 begin
  v0:=c0;v1:=c1;vv:=cv-1;
  while vv<>0 do
  begin
   if v0>v1 then inc(v1) else inc(v0);
   dec(vv);
  end;
  if (v0=v1)or(v0=v1+1) then writeln('01');
 end;

 if s[l]='0' then 
 begin
  v0:=c0-1;v1:=c1;vv:=cv;
  while vv<>0 do
  begin
   if v0+1>=v1 then inc(v1) else inc(v0);
   dec(vv);
  end;
  if (v0+1=v1)or(v0+2=v1) then writeln('10');
 end;
 if s[l]='?' then
 begin
  v0:=c0;v1:=c1;vv:=cv-1;
  while vv<>0 do
  begin
   if v0+1>=v1 then inc(v1) else inc(v0);
   dec(vv);
  end;
  if (v0+1=v1)or(v0+2=v1) then writeln('10');
 end;
 if c1+cv>c0+1 then writeln('11');
end.