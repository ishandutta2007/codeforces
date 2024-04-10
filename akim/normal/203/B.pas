var a:array[-10..1010,-10..1010]of boolean;
    n,m,x,y,i:longint;
begin
 readln(n,m);
 for i:=1 to m do
 begin
  readln(x,y);
  a[x,y]:=true;
  if (a[x-2,y-2])and(a[x-2,y-1])and(a[x-2,y])and
     (a[x-1,y-2])and(a[x-1,y-1])and(a[x-1,y])and
     (a[x,y-2])and(a[x,y-1])and(a[x,y])then begin writeln(i);halt(0);end;
  if (a[x-1,y-2])and(a[x-1,y-1])and(a[x-1,y])and
     (a[x,y-2])and(a[x,y-1])and(a[x,y])and
     (a[x+1,y-2])and(a[x+1,y-1])and(a[x+1,y])then begin writeln(i);halt(0);end;
  if (a[x,y-2])and(a[x,y-1])and(a[x,y])and
     (a[x+1,y-2])and(a[x+1,y-1])and(a[x+1,y])and
     (a[x+2,y-2])and(a[x+2,y-1])and(a[x+2,y])then begin writeln(i);halt(0);end;

  if (a[x-2,y-1])and(a[x-2,y])and(a[x-2,y+1])and
     (a[x-1,y-1])and(a[x-1,y])and(a[x-1,y+1])and
     (a[x,y-1])and(a[x,y])and(a[x,y+1])then begin writeln(i);halt(0);end;
  if (a[x-1,y-1])and(a[x-1,y])and(a[x-1,y+1])and
     (a[x,y-1])and(a[x,y])and(a[x,y+1])and
     (a[x+1,y-1])and(a[x+1,y])and(a[x+1,y+1])then begin writeln(i);halt(0);end;
  if (a[x,y-1])and(a[x,y])and(a[x,y+1])and
     (a[x+1,y-1])and(a[x+1,y])and(a[x+1,y+1])and
     (a[x+2,y-1])and(a[x+2,y])and(a[x+2,y+1])then begin writeln(i);halt(0);end;

  if (a[x-2,y])and(a[x-2,y+1])and(a[x-2,y+2])and
     (a[x-1,y])and(a[x-1,y+1])and(a[x-1,y+2])and
     (a[x,y])and(a[x,y+1])and(a[x,y+2])then begin writeln(i);halt(0);end;
  if (a[x-1,y])and(a[x-1,y+1])and(a[x-1,y+2])and
     (a[x,y])and(a[x,y+1])and(a[x,y+2])and
     (a[x+1,y])and(a[x+1,y+1])and(a[x+1,y+2])then begin writeln(i);halt(0);end;
  if (a[x,y])and(a[x,y+1])and(a[x,y+2])and
     (a[x+1,y])and(a[x+1,y+1])and(a[x+1,y+2])and
     (a[x+2,y])and(a[x+2,y+1])and(a[x+2,y+2])then begin writeln(i);halt(0);end;

 end;
 writeln(-1);
end.