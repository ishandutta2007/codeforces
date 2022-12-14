program dream_hyojool;
const maxN=100000+1067;
var
    res1,res2,avail:array[0..maxN] of integer;
    rr1,rr2,dem2,dem1,n,m,i,j:integer;
    x:char;       st1,st2:boolean;
    w:array[0..maxN*2] of char;
    u,v,head,link:array[0..maxN*2] of integer;
    dem:array[0..2,0..maxN] of integer;

function dfs(i,p:integer;x:char):boolean;
var p1,h:integer;
begin
    if avail[i]<>0 then exit(avail[i]=p);
    if p=1 then
       begin
           inc(dem1);
           dem[1][dem1]:=i
       end else
       begin
           inc(dem2);
           dem[2][dem2]:=i;
       end;
    avail[i]:=p;
    h:=head[i];
    while h>0 do
       begin
          if w[h]=x then
             begin
                 if dfs(v[h],p,x)=false then exit(false)
             end else
             begin
                 if p=1 then p1:=2 else p1:=1;
                 if dfs(v[h],p1,x)=false then exit(false)
             end;
          h:=link[h]
       end;
    exit(true)
end;

begin
    //assign(input,'dream_hyojoo.inp');
    //reset(input);
    readln(n,m);
    for i:=1 to m do
        begin
            readln(u[i],v[i],x,w[i]);
            link[i]:=head[u[i]];
            head[u[i]]:=i;
            v[i+m]:=u[i];
            link[i+m]:=head[v[i]];
            head[v[i]]:=i+m;
            w[i+m]:=w[i];
        end;
    x:='R';
    for  i:=1 to n do
    if avail[i]=0 then
         begin
              dem1:=0;
              dem2:=0;
              if not dfs(i,1,x) then st1:=true;
              if st1 then break;
              if dem1<dem2 then
                 begin
                     for j:=1 to dem1 do
                         begin
                            inc(rr1);
                            res1[rr1]:=dem[1][j]
                         end
                 end else
                 begin
                     for j:=1 to dem2 do
                         begin
                            inc(rr1);
                            res1[rr1]:=dem[2][j]
                         end
                 end
         end;
    x:='B';
    fillchar(avail,sizeof(avail),0);
    for  i:=1 to n do
    if avail[i]=0 then
         begin
              dem1:=0;
              dem2:=0;
              if not dfs(i,1,x) then st2:=true;
              if st2 then break;
              if dem1<dem2 then
                 begin
                     for j:=1 to dem1 do
                         begin
                            inc(rr2);
                            res2[rr2]:=dem[1][j]
                         end
                 end else
                 begin
                     for j:=1 to dem2 do
                         begin
                            inc(rr2);
                            res2[rr2]:=dem[2][j]
                         end
                 end
         end;
    if st1 and st2 then writeln(-1) else
    if not st1 and (st2 or (rr1<rr2)) then
       begin
           writeln(rr1);
           for i:=1 to rr1 do write(res1[i],' ');
           writeln
       end else
       begin
           writeln(rr2);
           for i:=1 to rr2 do write(res2[i],' ');
           writeln
       end;
end.