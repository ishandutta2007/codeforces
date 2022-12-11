var t0,t1,t2,x1,x2,oti,otf:int64;i,f:longint;otr,vr:extended;
begin
 readln(t1,t2,x1,x2,t0);
 if (t1=t2) then begin writeln(x1,' ',x2);halt(0);end;
 if t1=t0 then begin writeln(x1,' ',0);halt(0);end;
 if t2=t0 then begin writeln(0,' ',x2);halt(0);end;
 otr:=10000000;oti:=0;otf:=0;
 for i:=x1 downto 0 do
 begin
  f:=trunc(-((t0-t1)*i)/(t0-t2));
  if (f<=x2)and(f>=0)and((f<>0)or(i<>0)) then
  begin
   vr:=(t1*i+t2*f)/(i+f);
   if (vr-t0<otr-t0)and(vr>=t0) then begin otr:=vr;oti:=i;otf:=f;end;
  end;
  f:=f+1;
  if (f<=x2)and(f>=0)and((f<>0)or(i<>0)) then
  begin
   vr:=(t1*i+t2*f)/(i+f);
   if (vr-t0<otr-t0)and(vr>=t0) then begin otr:=vr;oti:=i;otf:=f;end;
  end;
  f:=f-2;
  if (f<=x2)and(f>=0)and((f<>0)or(i<>0)) then
  begin
   vr:=(t1*i+t2*f)/(i+f);
   if (vr-t0<otr-t0)and(vr>=t0) then begin otr:=vr;oti:=i;otf:=f;end;
  end;
 end;
 if oti=0 then otf:=x2;
 if otf=0 then oti:=x1;
 writeln(oti,' ',otf);
end.