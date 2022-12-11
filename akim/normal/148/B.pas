var vp,vd,t,x:longint;s,f,f1,p:extended;
function fun(x:extended):extended;
begin
 fun:=(-((vp*x)+(p-s)))/(vp-vd);
end;
begin
 readln(vp,vd,t,f,s);p:=s;f1:=f;
 if vp>=vd then begin writeln(0);halt(0);end;
 s:=s-vp*(fun(t)+t);
 f:=f1+(p-s)/vd;
 x:=0;
 while s>0 do
 begin
  s:=s-vp*(fun(f)+f);
  f:=f1+(p-s)/vd;
  inc(x);
 end;
 writeln(x);
end.